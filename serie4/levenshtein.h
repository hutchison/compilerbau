/*!
\file
\brief definition and implementation of the Levenshtein distance
\note This file must not be changed.
\note Function #levenshtein_distance uses a template, so this header also
contains its implementation.
*/

#pragma once

#include <vector>

/*!
\brief Levenshtein distance between to strings

taken from <http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance>

\param[in] s1  an object that implements size() and operator[].
\param[in] s2  an object that implements size() and operator[].
\return the Levenshtein distance between s1 and s2

\note This function should be used in the bonus task.
*/
template<class T>
unsigned int levenshtein_distance(const T& s1, const T& s2) {
    const size_t len1 = s1.size(), len2 = s2.size();
    std::vector<unsigned int> col(len2 + 1), prevCol(len2 + 1);

    for (unsigned int i = 0; i < prevCol.size(); i++) {
        prevCol[i] = i;
    }
    for (unsigned int i = 0; i < len1; i++) {
        col[0] = i + 1;
        for (unsigned int j = 0; j < len2; j++)
            col[j + 1] = std::min(std::min(1 + col[j], 1 + prevCol[1 + j]),
                                  prevCol[j] + (s1[i] == s2[j] ? 0 : 1));
        col.swap(prevCol);
    }
    return prevCol[len2];
}
