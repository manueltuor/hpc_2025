FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y g++ make python3 python3-pip python3-venv && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /poisson

COPY . .

RUN make

CMD ["./main"]
