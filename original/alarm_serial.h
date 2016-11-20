
/* Returns the number of days to the start of the specified year, taking leap
 * years into account, but not the shift from the Julian calendar to the
 * Gregorian calendar. Instead, it is as though the Gregorian calendar is
 * extrapolated back in time to a hypothetical "year zero".
 */
int leap (int year)
{
  return year*365 + (year/4) - (year/100) + (year/400);
}

/* Returns a number representing the number of days since March 1 in the
 * hypothetical year 0, not counting the change from the Julian calendar
 * to the Gregorian calendar that occured in the 16th century. This
 * algorithm is loosely based on a function known as "Zeller's Congruence".
 * This number MOD 7 gives the day of week, where 0 = Monday and 6 = Sunday.
 */
int zeller (int year, int month, int day)
{
  year += ((month+9)/12) - 1;
  month = (month+9) % 12;
  return leap (year) + month*30 + ((6*month+5)/10) + day + 1;
}

/* Returns the day of week (1=Monday, 7=Sunday) for a given date.
 */
int dow (int year, int month, int day)
{
  return (zeller (year, month, day) % 7) + 1;
}

DateTime getSerialTime()
{
  // Enter time in 24 hour format
  // Day of Week: Sunday == 0, Monday == 1, ..
  // Month:       Jan    == 0, Feb    == 1, ..
  // ty2016m00d10h20m26s01w0
  int nyear, nmonth, nday, nhour, nmin, nsec, ndow;
  
  if (Serial.peek() == 't')
  {
    Serial.read();
    
    if (Serial.peek() == 'y')
    {
      Serial.read();
      nyear = Serial.parseInt();
    }
    
    if (Serial.peek() == 'm')
    {
      Serial.read();
      nmonth = Serial.parseInt();
    }

    if (Serial.peek() == 'd')
    {
      Serial.read();
      nday = Serial.parseInt();
    }
    
    if (Serial.peek() == 'h')
    {
      Serial.read();
      nhour = Serial.parseInt();
    }

    if (Serial.peek() == 'm')
    {
      Serial.read();
      nmin = Serial.parseInt();
    }

    if (Serial.peek() == 's')
    {
      Serial.read();
      nsec = Serial.parseInt();
    }

    if (Serial.peek() == 'w')
    {
      Serial.read();
      ndow = Serial.parseInt();
    }

    ndow = dow(nyear, nmonth, nday);

    DateTime dt(nyear, nmonth, nday, nhour, nmin, nsec, ndow);
    //rtc.setDateTime(dt); //Adjust date-time as defined 'dt' above
    return dt;
  }
  else
  {
    Serial.println("No Time given");
  }
  Serial.flush();
}

