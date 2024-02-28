#pragma once

template <typename Container>
void insertionSort(Container& lyst, int left, int right) {
    int i = left + 1;
    while (i <= right) {
        auto itemToInsert = std::move(lyst[i]);
        int j = i - 1;
        while (j >= 0) {
            if (itemToInsert < lyst[j]) {
                lyst[j + 1] = lyst[j];
                j -= 1;
            } else {
                break;
            }
        }
        lyst[j + 1] = std::move(itemToInsert);
        i += 1;
    }
}

template <typename Container>
auto& median3(Container& lyst, int left, int right) {
    int center = ( left + right ) / 2;
    
    if( lyst[ center ] < lyst[ left ] )
        std::swap( lyst[ left ], lyst[ center ] );
    if( lyst[ right ] < lyst[ left ] )
        std::swap( lyst[ left ], lyst[ right ] );
    if( lyst[ right ] < lyst[ center ] )
        std::swap( lyst[ center ], lyst[ right ] );

        // Place pivot at position right - 1
    std::swap( lyst[ center ], lyst[ right - 1 ] );
    return lyst[ right - 1 ];
}

template <typename Container>
int partition(Container& lyst, int left, int right) {
    auto& pivot = median3( lyst, left, right );

        // Begin partitioning
    int i = left, j = right - 1;
    for( ; ; )
    {
        while( lyst[ ++i ] < pivot ) { }
        while( pivot < lyst[ --j ] ) { }
        if( i < j )
            std::swap( lyst[ i ], lyst[ j ] );
        else
            break;
    }

    std::swap( lyst[ i ], lyst[ right - 1 ] );  // Restore pivot
    return i;
}

template <typename Container>
void quicksortHelper(Container& lyst, int left, int right ) {
    if( left + 10 <= right )
    {
        auto pivotLocation = partition(lyst, left, right);
        quicksortHelper(lyst, left, pivotLocation - 1);
        quicksortHelper(lyst, pivotLocation + 1, right);
    }
    else  // Do an insertion sort on the subarray
        insertionSort( lyst, left, right );
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Container>
void quicksort(Container& lyst ) {
    quicksortHelper(lyst, 0, lyst.size( ) - 1);
}


