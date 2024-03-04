FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y valgrind gcc make xorg libx11-dev libxext-dev libbsd-dev zlib1g-dev

WORKDIR /miniRT
COPY . /miniRT

CMD ["/bin/bash"]
