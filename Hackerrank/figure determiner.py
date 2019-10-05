while(2==2):
   print("_________________________________________________")
   print("""Program can determine till 6 angles only.
   and remember if you have angles less than 6 simply enter 0""")
   print("_________________________________________________")
   get = int(input("Enter first angle:"))
   print("_________________________________________________")
   get_again = int(input("Enter second angle:"))
   print("_________________________________________________")
   get_again_again = int(input("Enter third angle:"))
   print("_________________________________________________")
   get_it = int(input("Enter fourth angle:"))
   print("_________________________________________________")
   get_it_it = int(input("Enter fifth angle:"))
   print("_________________________________________________")
   getting = int(input("Enter sixth angle:"))
   print("_________________________________________________")

   if get + get_again + get_again_again + get_it  + get_it_it + getting == 180:
       print("The figure is Triangle or linear pair of angles")
       print("_________________________________________________")
   elif get + get_again + get_again_again + get_it  + get_it_it + getting == 360:
       print("The figure is Quadrilateral ")
   elif get + get_again + get_again_again + get_it  + get_it_it + getting == 540:
       print("The figure is Pentagon")      
   elif get + get_again + get_again_again + get_it  + get_it_it + getting == 720:
       print("The figure is Hexagon")      

   feature = raw_input("Start again or End:")
   if feature == "Start again":
       print("Starting again...")
       print("Started again")
       continue
   elif feature == "End":
       print("Program Ended...")
       print("_________________________________________________")
       print(" ")
       break
       
