# Given a time in -hour AM/PM format,
# convert it to military (24-hour) time.


def timeConversion(s) # Example s = 07:05:45PM string
  day = s[8..9]
  s_arr = s[0..7].split(":")
  hrs = s_arr[0].to_i
  if (hrs >= 1 )&& (hrs < 12) && (day == "AM") # if the hours are from 1 am to 11:59 AM
    return s[0..7]
  elsif hrs == 12
    if day == "AM" # 12 AM -- 00
      s_arr[0] = "00"
    elsif day == "PM"
      return s[0..7]
    end
  elsif day == "PM"
    s_arr[0] = "#{s_arr[0].to_i + 12}"
  end
  return s_arr.join(":")
end

# test cases 
# p timeConversion("12:05:45AM") + " = 12:05:45"
# p timeConversion("01:05:45AM") + " = 01:05:45"
# p timeConversion("02:05:45AM") + " = 02:05:45"
# p timeConversion("05:05:45AM") + " = 05:05:45"
# p timeConversion("08:05:45AM") + " = 08:05:45"
# p timeConversion("10:05:45AM") + " = 10:05:45"
# p timeConversion("11:05:45AM") + " = 11:05:45"
# p timeConversion("12:05:45PM") + " = 12:05:45"
# p timeConversion("01:05:45PM") + " = 13:05:45"
# p timeConversion("02:05:45PM") + " = 14:05:45"
# p timeConversion("05:05:45PM") + " = 17:05:45"
# p timeConversion("07:05:45PM") + " = 19:05:45"
# p timeConversion("10:05:45PM") + " = 22:05:45"
# p timeConversion("11:05:45PM") + " = 23:05:45"
# p timeConversion("12:00:00AM") + " = 00:00:00"
