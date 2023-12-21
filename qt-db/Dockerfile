# Use Ubuntu 18.04 as the base image
FROM ubuntu:18.04 AS build

# Install build dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    wget \
    libssl-dev \
    qt5-default \ 
    libqt5sql5-mysql \
    && rm -rf /var/lib/apt/lists/*

# The rest of your Dockerfile remains the same
# ...

# Build steps for your application
# ...

# Final stage
FROM ubuntu:18.04
# Copy necessary libraries and binaries as before
# ...

# Set command to run your application
CMD ["/app/qt-db"]
