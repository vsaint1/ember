#pragma once

#include <SDL3/SDL.h>
#include <cstdio>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <cstdlib>
#include <ctime>

#define LOG_INFO(fmt, ...) fprintf(stdout, "[INFO] - " fmt "\n", ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERROR] - " fmt "\n", ##__VA_ARGS__)