import barcode
barcode_formats = barcode.PROVIDED_BARCODES

print(barcode_formats)
import barcode
from barcode.writer import ImageWriter
number = '049000042511'
barcode_format = barcode.get_barcode_class('upc')


my_barcode = barcode_format(number, writer=ImageWriter())

my_barcode.save("generated_barcode")
import barcode
from barcode.writer import ImageWriter
  
#Define content of the barcode as a string
number = '049000042511'

#Get the required barcode format
barcode_format = barcode.get_barcode_class('upc')

#Generate barcode and render as image
my_barcode = barcode_format(number, writer=ImageWriter())
  
#Save barcode as PNG
my_barcode.save("generated_barcode")







