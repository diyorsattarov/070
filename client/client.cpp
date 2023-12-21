#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>
#include <string>
#include "json.hpp"  // nlohmann JSON header

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

using json = nlohmann::json;

int main() {
    try {
        auto const host = "server";
        auto const port = "80";
        auto const target = "/submit-data";  // Target URI
        int version = 11;  // HTTP version (11 = 1.1)

        // Set up an IO context and a resolver
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        beast::tcp_stream stream(ioc);

        // Resolve the host and establish a connection
        auto const results = resolver.resolve(host, port);
        stream.connect(results);

        // Create a JSON object
        json j;
        j["name"] = "John Doe";
        j["age"] = 30;
        j["email"] = "johndoe@example.com";

        // Convert JSON object to string
        std::string json_string = j.dump();

        // Set up the HTTP POST request
        http::request<http::string_body> req{http::verb::post, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        req.set(http::field::content_type, "application/json");
        req.content_length(json_string.size());
        req.body() = json_string;

        // Send the HTTP request
        http::write(stream, req);

        // Receive the HTTP response
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(stream, buffer, res);

        // Output the response
        std::cout << res << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        stream.socket().shutdown(tcp::socket::shutdown_both, ec);

        // Not_connected happens sometimes so don't bother reporting it.
        if(ec && ec != beast::errc::not_connected)
            throw beast::system_error{ec};
    }
    catch(std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
