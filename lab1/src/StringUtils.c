void stripString(char *str) {
    while (*str != '\0') {
        if (*str == '\n') {
            *str = '\0';
            return;
        }
        ++str;
    }
}

int compareString(const char *s1, const char *s2) {
    unsigned char c1, c2;

    do {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);

    return c1 - c2;
}

void utils_uint2str_hex(unsigned int num, char* str) {
    // num=7114 digit=4
    unsigned int temp = num;
    int digit = -1;
    *str = '0';
    *str++;
    *str = 'x';
    *str++;
    if (num == 0) {
        *str = '0';
        str++;
    }
    else {
        while (temp > 0) {
            temp /= 16;
            digit++;
        }
        for (int i = digit;i >= 0;i--) {
            int t = 1;
            for (int j = 0;j < i;j++) {
                t *= 16;
            }
            if (num / t >= 10) {
                *str = '0' + num / t + 39;
            }
            else {
                *str = '0' + num / t;
            }
            num = num % t;
            str++;
        }

    }

    *str = '\0';
}
