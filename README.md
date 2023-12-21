# RESTPP

### Dependencies
1. Docker

### Demo

```
➜  rest-pp git:(master) ✗ docker-compose up --build --remove-orphans
[+] Building 13.0s (26/26) FINISHED                                                                                                   docker:default
 => [server internal] load build definition from Dockerfile                                                                                     0.1s
 => => transferring dockerfile: 1.38kB                                                                                                          0.0s
 => [server internal] load .dockerignore                                                                                                        0.0s
 => => transferring context: 2B                                                                                                                 0.0s
 => [client internal] load metadata for docker.io/library/ubuntu:18.04                                                                          0.8s
 => [server internal] load build context                                                                                                        0.0s
 => => transferring context: 160B                                                                                                               0.0s
 => [client build 1/7] FROM docker.io/library/ubuntu:18.04@sha256:152dc042452c496007f07ca9127571cb9c29697f42acbfad72324b2bb2e43c98              0.0s
 => CACHED [client stage-1 2/5] RUN apt-get update && apt-get install -y     libssl-dev     && rm -rf /var/lib/apt/lists/*                      0.0s
 => CACHED [client build 2/7] RUN apt-get update && apt-get install -y     g++     cmake     git     wget     libssl-dev     && rm -rf /var/li  0.0s
 => CACHED [client build 3/7] RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.73.0/source/boost_1_73_0.tar.gz     && tar -xzf bo  0.0s
 => CACHED [client build 4/7] RUN ls /usr/local/lib/                                                                                            0.0s
 => CACHED [client build 5/7] WORKDIR /app                                                                                                      0.0s
 => CACHED [server build 6/7] COPY . /app                                                                                                       0.0s
 => CACHED [server build 7/7] RUN cmake . && make                                                                                               0.0s
 => CACHED [server stage-1 3/6] COPY --from=build /usr/local/lib/ /usr/local/lib/                                                               0.0s
 => CACHED [server stage-1 4/6] COPY --from=build /usr/local/include/boost/ /usr/local/include/boost/                                           0.0s
 => CACHED [server stage-1 5/6] RUN ldconfig                                                                                                    0.0s
 => CACHED [server stage-1 6/6] COPY --from=build /app/server /app/server                                                                       0.0s
 => [server] exporting to image                                                                                                                 0.0s
 => => exporting layers                                                                                                                         0.0s
 => => writing image sha256:eb9cb1c1ab487809766e0446c99c8ed91d11c2e85251d7dd4597e8a341473049                                                    0.0s
 => => naming to docker.io/library/rest-pp-server                                                                                               0.0s
 => [client internal] load .dockerignore                                                                                                        0.0s
 => => transferring context: 2B                                                                                                                 0.0s
 => [client internal] load build definition from Dockerfile                                                                                     0.0s
 => => transferring dockerfile: 1.37kB                                                                                                          0.0s
 => [client internal] load build context                                                                                                        0.0s
 => => transferring context: 1.47kB                                                                                                             0.0s
 => [client build 6/7] COPY . /app                                                                                                              0.1s
 => [client build 7/7] RUN cmake . && make                                                                                                     10.1s
 => CACHED [client stage-1 3/5] COPY --from=build /usr/local/lib/ /usr/local/lib/                                                               0.0s
 => CACHED [client stage-1 4/5] COPY --from=build /usr/local/include/boost/ /usr/local/include/boost/                                           0.0s
 => CACHED [client stage-1 5/5] COPY --from=build /app/client /app/client                                                                       0.0s
 => [client] exporting to image                                                                                                                 0.0s
 => => exporting layers                                                                                                                         0.0s
 => => writing image sha256:da4d9d91525c2e18880d45cf001071be84009cdb9f4d00eb16f63d3df9e366b5                                                    0.0s
 => => naming to docker.io/library/rest-pp-client                                                                                               0.0s
[+] Running 2/2
 ✔ Container rest-pp-server-1  Created                                                                                                          0.0s 
 ✔ Container rest-pp-client-1  Recreated                                                                                                        0.2s 
Attaching to client-1, server-1
server-1  | [2023-12-21 02:19:31.884109] [0x00007f9e9d67e500] [info]    http_connection
server-1  | [2023-12-21 02:19:31.884155] [0x00007f9e9d67e500] [debug]   Reading request
client-1  | HTTP/1.1 200 OK
client-1  | Connection: close
client-1  | Content-Type: text/plain
server-1  | [2023-12-21 02:19:31.884288] [0x00007f9e9d67e500] [info]    Data: {"key":"value"}
client-1  | Content-Length: 27
client-1  | 
client-1  | Data received successfully.
client-1 exited with code 0
```