//
// sync_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "curl.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}


int main(int argc, char *argv[]) {
    CURLcode res;
    CURL *curl = curl_easy_init();
    if (curl) {
        char *output = curl_easy_escape(curl, "Hello Walter, I am Jarvis.", 15);
        curl_easy_setopt(curl, CURLOPT_URL, "http://translate.google.com/translate_tts?tl=en&q=Hello Walter");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_free(output);
    }
    return 0;
}