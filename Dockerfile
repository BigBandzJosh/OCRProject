# Use an official gcc runtime as a parent image
FROM ubuntu:20.04

# Set the working directory in the container to /app
WORKDIR /app

# Install any needed packages specified in requirements.txt
RUN apt-get update && \
    apt-get install -y libleptonica-dev libtesseract-dev \
    cmake g++ make

# Copy the current directory contents into the container at /app
COPY . /app

# Generate Makefile
RUN cmake .

# Build the project
RUN make

# Run Tesseract when the container launches
CMD ["./Tesseract", "Luna.png"]