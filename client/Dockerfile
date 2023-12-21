# Use Ubuntu 18.04 as the base image
FROM ubuntu:18.04 AS build

# Install build dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    wget \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Download and build Boost
RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.73.0/source/boost_1_73_0.tar.gz \
    && tar -xzf boost_1_73_0.tar.gz \
    && cd boost_1_73_0 \
    && ./bootstrap.sh --with-libraries=system,thread,chrono,date_time,atomic,regex,random,filesystem,program_options,log, log_setup \
    && ./b2 install
RUN ls /usr/local/lib/
# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Build the application
RUN cmake . && make

# Set the base image for the final stage
FROM ubuntu:18.04

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy the Boost libraries from the build stage
COPY --from=build /usr/local/lib/ /usr/local/lib/
COPY --from=build /usr/local/include/boost/ /usr/local/include/boost/

EXPOSE 80

# Copy the binaries from the build stage
COPY --from=build /app/client /app/client

# Set the command to run the application
CMD ["/app/client", "server", "80", "/submit-data", "{\"key\": \"value\"}"]
