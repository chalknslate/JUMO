#ifndef INTEGER_H_
#define INTEGER_H_
#include <stdio.h>
struct Integer {
    int value;
    void (*print)(struct Integer* self);
};

void print(struct Integer* self) {
    printf("%d\n", self->value);
}
inline static struct Integer newInt(int value) {
    return (struct Integer) {
        .value = value,
        .print = &print,
    };
}

static const struct {
    struct Integer (*new)(int value);
} Integer = {.new = &newInt};
#endif