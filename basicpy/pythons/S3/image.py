import cv2
from matplotlib import pyplot as plt

img = cv2.imread(r"C:\Users\dhanu\code\basicpy\pythons\S3\tanjiro_pic.jpg", 1)
if img is None:
  print("Error reading the file!!!")
else:
  print(img)
  cv2.imshow('special',img)
  cv2.waitKey(0)
  cv2.destroyAllWindows()
  cv2.imwrite('tangiro_copy.jpg',img)
  image_rgb=cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
  plt.imshow(image_rgb)
  plt.title("Displayed image using maplot lib.")
  plt.axis("off")
  plt.show()