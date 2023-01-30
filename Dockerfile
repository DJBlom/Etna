# Image that will be used
FROM fedora:36

# Shell that will be used
SHELL ["/bin/bash", "-c"]

# Setting up the user environment
RUN groupadd --gid=1002 odin && \ 
    useradd --uid=1001 --gid=odin --create-home odin && \
    echo "odin ALL=NOPASSWD : ALL" >> /etc/sudoers && \
    sudo -u odin mkdir /home/odin/project && \
    sudo -u odin mkdir /home/odin/bin && \
    sudo -u odin mkdir -p /home/odin/.local/bin

# Setting up the development environment
RUN dnf -y install docker-compose \
    python3 libxcrypt-compat \
    curl gcc gcc-c++ \
    make cmake autoconf \
    automake git libtool \
    dh-autoreconf lcov \
    cppcheck vim openocd \
    gdb 


WORKDIR /home/odin
RUN git clone https://github.com/cpputest/cpputest.git
WORKDIR /home/odin/cpputest
RUN autoreconf --install
RUN ./configure
RUN make tdd
RUN echo "export CPPUTEST_HOME=$(pwd)" >> /home/odin/.bashrc
ENV PATH "$PATH:/home/odin/cpputest"

# Providing system information like adding things to the path and setting up the language to be used
ENV PATH=/home/odin/bin:$PATH \
    LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=C.UTF-8

ENV HOME /home/odin

# Finnishing off by setting the user and changing into the project directory
USER odin
WORKDIR /home/odin/project
