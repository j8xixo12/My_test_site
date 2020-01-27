#include "builder.hpp"

int main(int argc, char *argv[]) {
    Consumer consumer;
    F18 f18;
    A320 a320;

    consumer.ProducePlane(&f18);
    consumer.SeePlane();

    consumer.ProducePlane(&a320);
    consumer.SeePlane();

    return 0;
}