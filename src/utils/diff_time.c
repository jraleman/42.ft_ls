// http://forums.devshed.com/programming-42/source-code-difftime-360300.html

/* Return the difference between TIME1 and TIME0.  */
double diff_time (time_t t1, time_t t0)
{
  /* Convert to double and then subtract if no double-rounding error could
     result.  */

  if (TYPE_BITS (time_t) <= DBL_MANT_DIG
      || (TYPE_FLOATING (time_t) && sizeof (time_t) < sizeof (long double)))
    return (double) t1 - (double) t0;

  /* Likewise for long double.  */

  if (TYPE_BITS (time_t) <= LDBL_MANT_DIG || TYPE_FLOATING (time_t))
    return (long double) t1 - (long double) t0;

  /* Subtract the smaller integer from the larger, convert the difference to
     double, and then negate if needed.  */

  return t1 < t0 ? - subtract (t0, t1) : subtract (t1, t0);
}