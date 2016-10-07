//
// Created by walter on 05/10/16.
//

#ifndef JARVIS_PAGE_HPP
#define JARVIS_PAGE_HPP

#include <cstddef>
#include <vector>

namespace repository {


    template<class T>
    class Page {
    public:
        std::vector<T> getContent() {
            return content;
        }

        //Returns the number of the current page.
        size_t getNumber() {
            return number;
        }

        //Returns the number of elements currently on this page.
        size_t getNumberOfElements() {
            return content.size();
        }

        //Returns the size of the page.
        size_t getSize() {
            return size;
        }

        //Returns the total amount of elements.
        long getTotalElements() {
            return totalElements;
        }

        //Returns the number of total pages.
        size_t getTotalPages() {
            return totalPages;
        }

        //Returns whether the Page has content at all.
        bool hasContent() {
            return totalElements != 0;
        }

        //Returns if there is a next page.
        bool hasNextPage() {
            return true;
        }

        //Returns if there is a previous page.
        bool isFirstPage() {
            return false;
        }

        //Returns whether the current page is the first one.
        bool hasPreviousPage() {
            return false;
        }

        //Returns whether the current page is the last one.
        bool isLastPage() {
            return false;
        }
        // Pageable	nextPageable()
        // Pageable	previousPageable()
    private:
        std::vector<T> content;
        size_t size;
        size_t number;
        size_t totalElements;
        size_t totalPages;

    };

}

#endif //JARVIS_PAGE_HPP
