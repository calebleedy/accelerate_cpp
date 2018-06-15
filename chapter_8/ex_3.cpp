#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

template<class Ran, class T> T median(Ran beg, Ran end)
{
  T size = end - beg;
  if (size == 0) {
    throw domain_error("Median of an empty vector");
  }

  sort(beg, end);

  T mid = size / 2;

  return size % 2 == 0 ? (*(beg + mid) + *(beg + mid - 1)) / 2 : *(beg + mid);
}
