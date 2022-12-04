FROM ubuntu:20.04
LABEL Description="Build environment"

ENV HOME /root
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt install -y software-properties-common &&\
    add-apt-repository -y ppa:ubuntu-toolchain-r/test &&\
    apt-get install -y --no-install-recommends \
    gcc-11 \
    g++-11 \
    cmake \
    make \
    git \ 
    clang-format 

RUN update-alternatives --install /usr/bin/g++ g++-11 /usr/bin/g++-11 100 && \
    update-alternatives --install /usr/bin/gcc gcc-11 /usr/bin/gcc-11 100

# TODO: Install googletest inside the container rather than as part of the build.
# Perhaps this could be a multistage build?