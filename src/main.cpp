#include "UniquePtr.h"
#include <cassert>
#include <utility>

int main() {
    UniquePtr<int> unique_ptr = makeUnique<int>(0);
    for (int i = 1; i <= 10; ++i) {
        *unique_ptr = i;
        assert(*unique_ptr == i);
    }
    *unique_ptr = 5;
    
    UniquePtr<int> unique_ptr_taken_owner = UniquePtr<int>(std::move(unique_ptr));

    assert(*unique_ptr_taken_owner == 5);

    return 0;
}
