
// equal(b, e, d)
template<class In, class In2> bool equal(In beg, In end, In2 dest)
{
  while (beg != end) {
    if (beg++ != dest++) {
      return false;
    }
  }
  return true;
}

// search(b, e, b2, e2)
template<class Fwd, class Fwd2> Fwd search(Fwd beg, Fwd end, Fwd2 b2, Fwd2 e2)
{
  while (beg != end && *beg != *b2) {
    ++beg;
  }

  Fwd tmp = beg;

  while (beg != end && *beg == *b2 && b2 != e2) {
    ++beg;
    ++b2;
  }

  if (b2 == e2) {
    return tmp;
  } else { // either beg == end or *beg != *b2
    return end;
  } 

  return b2 == e2 ? tmp : end;

}

// find(b, e, t)
template<class In, class T> In find(In beg, In end, const T& x)
{
  while (beg != end) {
    if (*beg++ == x) {
      return beg;
    }
  }
  return beg;
}


// find_if(b, e, p)
template<class In, class T> In find_if(In beg, In end, const T& pred)
{
  while(beg != end && !pred(*beg)) {
    ++beg;
  }
  return beg;
}

// copy(b, e, d)
template<class In, class Out> Out copy(In beg, In end, Out dest)
{
  while (beg != end) {
    *dest++ = *beg++;
  }
  return dest;
}

// remove_copy(b, e, d, t)
template<class In, class Out, class X>
Out remove_copy(In beg, In end, Out dest, const X& x) {
  while (beg != end) {
    if (*beg != x) {
      *dest++ = *beg++;
    } else {
      ++beg;
    }
  }
  return dest;
}

// remove_copy_if(b, e, d, p)
template<class In, class Out, class X>
Out remove_copy_if(In beg, In end, Out dest, const X& pred)
{
  while (beg != end) {
    if (!pred(*beg)) {
      *dest++ = *beg++;
    } else {
      ++beg;
    }
  }
  return dest;
}

template<class T> void swap(T& x, T& y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

// remove(b, e, t)
template<class Bi, class X> Bi remove(Bi beg, Bi end, const X& x)
{
  while (beg != end) {
    if (*beg == x) {
      swap(*beg, *(--end));
      --end;
    } else {
      ++beg;
    }
  }

  return end;

}

// transform(b, e, d, f)
template<class In, class Out, class X> 
void transform(In beg, In end, Out dest, const X& fun)
{
  while (beg != end) {
    *dest++ = fun(*beg++);
  }
}

// partition(b, e, p)
template<class Bi, class X> Bi partition(Bi beg, Bi end, const X& pred)
{
  while (beg != end) {
    if (!pred(*beg)) {
      swap(*beg, *(--end));
      --end;
    } else {
      ++beg;
    }
  }

  return end;

}

// accumulate(b, e, t)
template<class In, class T> T accumulate(In beg, In end, T t)
{
  while (beg != end) {
    t += *beg++;
  }

  return t;
}


