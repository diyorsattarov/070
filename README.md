# RESTPP

### Dependencies
1. Docker

### Demo

```
➜  rest-pp git:(master) ✗ docker-compose up --build 
[+] Building 13.1s (27/27) FINISHED                                                                                                   docker:default
 => [server internal] load .dockerignore                                                                                                        0.1s
 => => transferring context: 2B                                                                                                                 0.0s
 => [server internal] load build definition from Dockerfile                                                                                     0.0s
 => => transferring dockerfile: 1.39kB                                                                                                          0.0s
 => [client internal] load metadata for docker.io/library/ubuntu:18.04                                                                          0.7s
 => [client build 1/7] FROM docker.io/library/ubuntu:18.04@sha256:152dc042452c496007f07ca9127571cb9c29697f42acbfad72324b2bb2e43c98              0.0s
 => [server internal] load build context                                                                                                        0.0s
 => => transferring context: 183B                                                                                                               0.0s
 => CACHED [client stage-1 2/6] RUN apt-get update && apt-get install -y     libssl-dev     && rm -rf /var/lib/apt/lists/*                      0.0s
 => CACHED [client build 2/7] RUN apt-get update && apt-get install -y     g++     cmake     git     wget     libssl-dev     && rm -rf /var/li  0.0s
 => CACHED [client build 3/7] RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.73.0/source/boost_1_73_0.tar.gz     && tar -xzf bo  0.0s
 => CACHED [client build 4/7] RUN ls /usr/local/lib/                                                                                            0.0s
 => CACHED [client build 5/7] WORKDIR /app                                                                                                      0.0s
 => CACHED [server build 6/7] COPY . /app                                                                                                       0.0s
 => CACHED [server build 7/7] RUN cmake . && make                                                                                               0.0s
 => CACHED [server stage-1 3/6] COPY --from=build /usr/local/lib/ /usr/local/lib/                                                               0.0s
 => CACHED [server stage-1 4/6] COPY --from=build /usr/local/include/boost/ /usr/local/include/boost/                                           0.0s
 => CACHED [server stage-1 5/6] RUN ldconfig                                                                                                    0.0s
 => CACHED [server stage-1 6/6] COPY --from=build /app/my_program /app/my_program                                                               0.0s
 => [server] exporting to image                                                                                                                 0.0s
 => => exporting layers                                                                                                                         0.0s
 => => writing image sha256:a9d0cdd4d2ccf3ad2b186dad56357c9315f92336aac7a85ad3360b1ab1684ba0                                                    0.0s
 => => naming to docker.io/library/rest-pp-server                                                                                               0.0s
 => [client internal] load .dockerignore                                                                                                        0.0s
 => => transferring context: 2B                                                                                                                 0.0s
 => [client internal] load build definition from Dockerfile                                                                                     0.1s
 => => transferring dockerfile: 1.38kB                                                                                                          0.0s
 => [client internal] load build context                                                                                                        0.0s
 => => transferring context: 1.50kB                                                                                                             0.0s
 => [client build 6/7] COPY . /app                                                                                                              0.1s
 => [client build 7/7] RUN cmake . && make                                                                                                      9.7s
 => CACHED [client stage-1 3/6] COPY --from=build /usr/local/lib/ /usr/local/lib/                                                               0.0s
 => CACHED [client stage-1 4/6] COPY --from=build /usr/local/include/boost/ /usr/local/include/boost/                                           0.0s
 => CACHED [client stage-1 5/6] RUN ldconfig                                                                                                    0.0s
 => [client stage-1 6/6] COPY --from=build /app/client /app/client                                                                              0.1s
 => [client] exporting to image                                                                                                                 0.1s
 => => exporting layers                                                                                                                         0.1s
 => => writing image sha256:ee0e2d3e75097021ad3dd47326a05882c09df414c6c9a3b9a848c34c0daaf1cc                                                    0.0s
 => => naming to docker.io/library/rest-pp-client                                                                                               0.0s
[+] Running 2/2
 ✔ Container rest-pp-server-1  Created                                                                                                          0.0s 
 ✔ Container rest-pp-client-1  Recreated                                                                                                        0.2s 
Attaching to client-1, server-1
server-1  | [2023-12-21 01:32:17.675483] [0x00007ff7a6674500] [info]    http_connection
server-1  | [2023-12-21 01:32:17.675541] [0x00007ff7a6674500] [debug]   Reading request
server-1  | [2023-12-21 01:32:17.675718] [0x00007ff7a6674500] [info]    Data: {"age":30,"email":"johndoe@example.com","name":"John Doe"}
client-1  | HTTP/1.1 200 OK
client-1  | Connection: close
client-1  | Content-Type: text/plain
client-1  | Content-Length: 27
client-1  | 
client-1  | Data received successfully.
client-1 exited with code 0
```