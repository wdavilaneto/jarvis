//
// Created by walter on 19/10/16.
//

#ifndef JARVIS_PAGEABLE_HPP
#define JARVIS_PAGEABLE_HPP


#include <cstddef>

namespace repository {

    class Pageable {
    public:

        Pageable(size_t offset, size_t pageNumber, size_t pageSize) : offset(offset),
                                                                      pageNumber(pageNumber),
                                                                      pageSize(pageSize) {

        }


        virtual ~Pageable() {

        }

        int getOffset() {
            return offset;
        }

        int getPageNumber() {
            return pageNumber;
        }

        int getPageSize() {
            return pageNumber;
        }

        bool operator!=(const Pageable &rhs) const {
            return !(rhs == *this);
        }

    private:
        size_t offset;
        size_t pageNumber;
        size_t pageSize;
    };

};

#endif //JARVIS_PAGEABLE_HPP
