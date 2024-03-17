#include "long_number.hpp"

namespace IBusko {
    LongNumber::LongNumber() {
        this->numbers = nullptr;
        this->length = 0;
        this->sign = POSITIVE;
    }

    LongNumber::LongNumber(const char *const str) {
        int size = 0;
        int local_sign = 0;
        if (str[0] == '-') {
            local_sign++;
            this->sign = NEGATIVE;
        } else {
            this->sign = POSITIVE;
        }
        while (str[size] != '\0') {
            size++;
        }
        this->length = size - local_sign;
        this->numbers = new int[this->length];
        for (int i = size - 1; i >= local_sign; i--) {
            this->numbers[size - i - 1] = (int) str[i] - 48;
        }
    }

    LongNumber::LongNumber(const LongNumber &x) {
        this->length = x.length;
        this->sign = x.sign;
        this->numbers = new int[this->length];
        for (int i = 0; i < this->length; i++) {
            this->numbers[i] = x.numbers[i];
        }
    }

    LongNumber::LongNumber(LongNumber &&x) {
        this->length = x.length;
        this->sign = x.sign;
        this->numbers = x.numbers;
        x.numbers = nullptr;
    }

    LongNumber::~LongNumber() {
        delete this->numbers;
    }

    LongNumber &LongNumber::operator=(const char *const str) {
        int size = 0;
        int local_sign = 0;
        if (str[0] == '-') {
            local_sign++;
            this->sign = NEGATIVE;
        } else {
            this->sign = POSITIVE;
        }
        while (str[size] != '\0') {
            size++;
        }
        this->length = size - local_sign;
        this->numbers = new int[this->length];
        for (int i = size - 1; i >= local_sign; i--) {
            numbers[size - i - 1] = (int) str[i] - 48;
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(const LongNumber &x) {
        this->length = x.length;
        this->sign = x.sign;
        this->numbers = new int[this->length];
        for (int i = 0; i < this->length; i++) {
            this->numbers[i] = x.numbers[i];
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(LongNumber &&x) {
        this->length = x.length;
        this->sign = x.sign;
        this->numbers = x.numbers;
        x.numbers = nullptr;
        return *this;
    }

    bool LongNumber::operator==(const LongNumber &x) {
        if (this->length == x.length && this->sign == x.sign) {
            for (int i = 0; i < this->length; i++) {
                if (this->numbers[i] != x.numbers[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool LongNumber::operator>(const LongNumber &x) {
        if (this->sign > x.sign) {
            return true;
        } else if (this->sign < x.sign) {
            return false;
        } else {
            if (this->sign == POSITIVE) {
                if (this->length > x.length) {
                    return true;
                } else if (this->length < x.length) {
                    return false;
                } else {
                    for (int i = this->length - 1; i >= 0; i--) {
                        if (this->numbers[i] < x.numbers[i]) {
                            return false;
                        } else if (this->numbers[i] > x.numbers[i]) {
                            return true;
                        }
                    }
                    return false;
                }
            } else {
                if (this->length > x.length) {
                    return false;
                } else if (this->length < x.length) {
                    return true;
                } else {
                    for (int i = this->length - 1; i >= 0; i--) {
                        if (this->numbers[i] < x.numbers[i]) {
                            return true;
                        } else if (this->numbers[i] > x.numbers[i]) {
                            return false;
                        }
                    }
                    return false;
                }
            }
        };
    }

    bool LongNumber::operator<(const LongNumber &x) {
        if (this->sign < x.sign) {
            return true;
        } else if (this->sign > x.sign) {
            return false;
        } else {
            if (this->sign == POSITIVE) {
                if (this->length < x.length) {
                    return true;
                } else if (this->length > x.length) {
                    return false;
                } else {
                    for (int i = this->length - 1; i >= 0; i--) {
                        if (this->numbers[i] > x.numbers[i]) {
                            return false;
                        } else if (this->numbers[i] < x.numbers[i]) {
                            return true;
                        }
                    }
                    return false;
                }
            } else {
                if (this->length < x.length) {
                    return false;
                } else if (this->length > x.length) {
                    return true;
                } else {
                    for (int i = this->length - 1; i >= 0; i--) {
                        if (this->numbers[i] > x.numbers[i]) {
                            return true;
                        } else if (this->numbers[i] < x.numbers[i]) {
                            return false;
                        }
                    }
                    return false;
                }
            }
        };
    }

    LongNumber LongNumber::operator+(const LongNumber &x) {
        LongNumber result;
        int sum;
        int sign;
        int ostatok = 0;
        int *a;
        int *b;
        if (this->length > x.length) {
            result.length = this->length + 1;
            a = new int[this->length];
            for (int i = 0; i < this->length; i++) {
                a[i] = this->numbers[i] * this->sign;
            }

            b = new int[this->length];
            for (int i = 0; i < x.length; i++) {
                b[i] = x.numbers[i] * x.sign;
            }
            for (int i = x.length; i < this->length; i++) {
                b[i] = 0;
            }
        } else {
            result.length = x.length + 1;
            a = new int[x.length];
            for (int i = 0; i < x.length; i++) {
                a[i] = x.numbers[i] * x.sign;
            }

            b = new int[x.length];
            for (int i = 0; i < this->length; i++) {
                b[i] = this->numbers[i] * this->sign;
            }
            for (int i = this->length; i < x.length; i++) {
                b[i] = 0;
            }
        }

        result.numbers = new int[result.length];
        for (int i = 0; i < result.length - 1; i++) {
            sum = a[i] + b[i] + ostatok;
            if (sum < 0 and sum > -10 and this->length != x.length and a[result.length - 2] > 0) {
                for (int p = i; p < result.length - 1; p++) {
                    if (a[p] != 0) {
                        for (int o = p; o > i + 1; o--) {
                            a[o] -= 1;
                            a[o - 1] += 10;
                        }
                        sum += 10;
                        a[i + 1] -= 1;
                        ostatok = 0;
                    }
                }
            } else {
                ostatok = sum / 10;
            }
            sum = sum % 10;
            if (sum >= 0) {
                sign = POSITIVE;
            } else {
                sign = NEGATIVE;
            }
            result.numbers[i] = abs(sum);
        }

        if (ostatok == 0) {
            int delta = 1;
            int index = 2;
            while (result.numbers[result.length - index] == 0) {
                delta++;
                index++;
            }
            result.length -= delta;
        } else {
            result.numbers[result.length - 1] = abs(ostatok);
        }
        result.sign = sign;

        delete a;
        delete b;
        return result;
    }

    LongNumber LongNumber::operator-(const LongNumber &x) {
        LongNumber result = *this;
        return result + (LongNumber("-1") * x);
    }

    LongNumber LongNumber::operator*(const LongNumber &x) {
        LongNumber result;
        int *one_oper = new int[x.length + 1];
        result.sign = this->sign * x.sign;
        result.length = this->length + x.length;
        result.numbers = new int[result.length];
        for (int i = 0; i < result.length; i++) {
            result.numbers[i] = 0;
        }
        int multy;
        int sum;
        for (int i = 0; i < this->length; i++) {
            int ostatok = 0;
            for (int j = 0; j < x.length; j++) {
                multy = this->numbers[i] * x.numbers[j] + ostatok;
                one_oper[j] = multy % 10;
                ostatok = multy / 10;
            }
            one_oper[x.length] = ostatok;
            int ostatok_2 = 0;
            for (int j = 0; j < x.length + 1; j++) {
                sum = result.numbers[i + j] + one_oper[j] + ostatok_2;
                result.numbers[i + j] = sum % 10;
                ostatok_2 = sum / 10;
            }
            if (ostatok_2 != 0) {
                result.numbers[i + x.length + 1] += ostatok_2;
            } else {
                result.length -= 1;
            }
        }
        return result;
    }

    LongNumber LongNumber::operator/(const LongNumber &x) {
        char *buffer_result = new char[this->length + 1];
        int index_2 = 0;
        for (int i = 0; i < this->length + 1; i++) {
            buffer_result[i] = '\0';
        }
        if (this->sign * x.sign < 0) {
            buffer_result[index_2] = '-';
            index_2++;
        }
        int index = 0;
        int num = 0;
        char *buffer = new char[x.length + 2];
        for (int i = 0; i < x.length + 2; i++) {
            buffer[i] = '\0';
        }
        for (int i = this->length - 1; i >= 0; i--) {
            if (LongNumber(buffer) < x) {
                buffer[index] = (char) this->numbers[i] + 48;
                index++;
            }
            if (LongNumber(buffer) > x || LongNumber(buffer) == x) {
                LongNumber longNumber_buffer(buffer);
                while (longNumber_buffer > x || longNumber_buffer == x) {
                    longNumber_buffer = longNumber_buffer - x;
                    num++;
                }
                buffer_result[index_2] = (char) num + 48;
                index_2++;
                num = 0;
                for (int p = 0; p < x.length + 2; p++) {
                    buffer[p] = '\0';
                }
                index = 0;
                for (int k = longNumber_buffer.length - 1; k >= 0; k--) {
                    buffer[longNumber_buffer.length - 1 - k] = (char) longNumber_buffer.numbers[k] + 48;
                    index++;
                }
            }
        }
        if (LongNumber(buffer) > x || LongNumber(buffer) == x) {
            LongNumber longNumber_buffer(buffer);
            while (longNumber_buffer > x || longNumber_buffer == x) {
                longNumber_buffer = longNumber_buffer - x;
                num++;
            }
            buffer_result[index_2] = num;
            index_2++;
        };
        return LongNumber(buffer_result);
    }

    LongNumber LongNumber::operator%(const LongNumber &x) {
        LongNumber result = *this;
        return result - ((result / x) * x);
    }

    int LongNumber::get_digits_number() const {
        return this->length;
    }

    bool LongNumber::is_positive() const {
        return this->sign == POSITIVE;
    }

    // ----------------------------------------------------------
    // PRIVATE
    // ----------------------------------------------------------
    int LongNumber::get_length(const char *const str) const {
        // TODO
        int length = 0;
        return length;
    }

    // ----------------------------------------------------------
    // FRIENDLY
    // ----------------------------------------------------------
    std::ostream &operator<<(std::ostream &os, const LongNumber &x) {
        if (x.sign == LongNumber::NEGATIVE) {
            std::cout << "-";
        }
        for (int i = x.length - 1; i >= 0; i--) {
            std::cout << x.numbers[i];
        }
        return os;
    }
}
