FROM ubuntu:latest

COPY . /usr/src/data_structure_lib_test

WORKDIR /usr/src/data_structure_lib_test

RUN apt-get update && apt-get install make libgtest-dev 

CMD make release; make test  