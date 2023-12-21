# Use the official Node.js image as a base
FROM node:14

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy package.json and package-lock.json (if available)
COPY package*.json ./

# Install dependencies
RUN npm install

# Bundle the source code inside the Docker image
COPY . .

# Expose the port on which the server is running
EXPOSE 3000

# Define the command to run the app
CMD ["node", "server.js"]
