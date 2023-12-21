# Use appropriate base image with Qt and MySQL
FROM ubuntu:22.04 AS build

# Install Qt, MySQL client, and other dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \ 
    qtbase5-dev-tools \
    libqt5sql5-mysql \
    && rm -rf /var/lib/apt/lists/*

# [Rest of your Dockerfile]


# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Build the application
RUN cmake . && make

# Use Ubuntu 22.04 as the base image for the final stage
FROM ubuntu:22.04

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libssl-dev \
    libqt5sql5-mysql \
    && rm -rf /var/lib/apt/lists/*

# Copy the binaries from the build stage
COPY --from=build /app/cpp-mysql /app/cpp-mysql

# Set the command to run the application
CMD ["/app/cpp-mysql", "SELECT * From users"]
