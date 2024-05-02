# Use an official Ubuntu 20.04 as a parent image
FROM ubuntu:20.04

# Set the environment variable
ENV DEBIAN_FRONTEND=noninteractive

# Set the working directory in the container to /app
WORKDIR /app

# Install any needed packages specified in requirements.txt
RUN apt-get update && \
    apt-get install -y libleptonica-dev libtesseract-dev tesseract-ocr-eng \
    cmake g++ make pkg-config


# Set the TESSDATA_PREFIX environment variable
ENV TESSDATA_PREFIX=/usr/share/tesseract-ocr/4.00/tessdata/

# Copy the current directory contents into the container at /app
COPY . /app

# Generate Makefile
RUN cmake .

# Build the project
RUN make
