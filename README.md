# RESTPP

### Dependencies
1. Docker

### Demo

```
[+] Running 4/4
 ✔ Container rest-pp-cpp-client-1      Removed                                                                                                  0.0s 
 ✔ Container rest-pp-express-server-1  Recreated                                                                                                0.4s 
 ✔ Container rest-pp-cpp-server-1      Created                                                                                                  0.0s 
 ✔ Container rest-pp-nginx-proxy-1     Recreated                                                                                                0.3s 
Attaching to cpp-server-1, express-server-1, nginx-proxy-1
express-server-1  | Express server running on http://localhost:3000
nginx-proxy-1     | /docker-entrypoint.sh: /docker-entrypoint.d/ is not empty, will attempt to perform configuration
nginx-proxy-1     | /docker-entrypoint.sh: Looking for shell scripts in /docker-entrypoint.d/
nginx-proxy-1     | /docker-entrypoint.sh: Launching /docker-entrypoint.d/10-listen-on-ipv6-by-default.sh
nginx-proxy-1     | 10-listen-on-ipv6-by-default.sh: info: Getting the checksum of /etc/nginx/conf.d/default.conf
nginx-proxy-1     | 10-listen-on-ipv6-by-default.sh: info: Enabled listen on IPv6 in /etc/nginx/conf.d/default.conf
nginx-proxy-1     | /docker-entrypoint.sh: Sourcing /docker-entrypoint.d/15-local-resolvers.envsh
nginx-proxy-1     | /docker-entrypoint.sh: Launching /docker-entrypoint.d/20-envsubst-on-templates.sh
nginx-proxy-1     | /docker-entrypoint.sh: Launching /docker-entrypoint.d/30-tune-worker-processes.sh
nginx-proxy-1     | /docker-entrypoint.sh: Configuration complete; ready for start up
express-server-1  | Received JSON: test
cpp-server-1      | [2023-12-21 02:50:23.560547] [0x00007f0e707a3500] [info]    http_connection
cpp-server-1      | [2023-12-21 02:50:23.560610] [0x00007f0e707a3500] [debug]   Reading request
cpp-server-1      | [2023-12-21 02:50:23.560864] [0x00007f0e707a3500] [info]    Data: jsonData=test
nginx-proxy-1     | 192.168.32.1 - - [21/Dec/2023:02:50:23 +0000] "POST /submit-data HTTP/1.1" 200 27 "http://localhost:3000/" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
nginx-proxy-1     | 2023/12/21 02:50:23 [error] 30#30: *1 open() "/etc/nginx/html/favicon.ico" failed (2: No such file or directory), client: 192.168.32.1, server: , request: "GET /favicon.ico HTTP/1.1", host: "localhost:8080", referrer: "http://localhost:8080/submit-data"
nginx-proxy-1     | 192.168.32.1 - - [21/Dec/2023:02:50:23 +0000] "GET /favicon.ico HTTP/1.1" 404 555 "http://localhost:8080/submit-data" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
^CGracefully stopping... (press Ctrl+C again to force)
[+] Stopping 0/2
 ⠼ Container rest-pp-nginx-proxy-1     Stopping                                                                                                 0.5s 
[+] Stopping 1/3t-pp-express-server-1  Stopping                                                                                                 0.5s 
[+] Stopping 2/3t-pp-nginx-proxy-1     Stopped                                                                                                  0.5s 
[+] Stopping 3/3t-pp-nginx-proxy-1     Stopped                                                                                                  0.5s 
 ✔ Container rest-pp-nginx-proxy-1     Stopped                                                                                                  0.5s 
 ✔ Container rest-pp-express-server-1  Stopped                                                                                                 10.4s 
 ✔ Container rest-pp-cpp-server-1      Stopped                                                                                                 10.6s 
cpp-server-1 exited with code 0
canceled
```