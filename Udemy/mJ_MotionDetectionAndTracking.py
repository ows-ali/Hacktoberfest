import cv2
import numpy as np

cap = cv2.VideoCapture(0)
#cap = cv2.VideoCapture('vtest.avi')

ret, frame1 = cap.read()
ret, frame2 = cap.read()

#diff = cv2.absdiff(frame1, frame2)
#gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
#blur = cv2.GaussianBlur(gray, (5,5), 0)
#_, thresh = cv2.threshold(blur, 20, 255, cv2.THRESH_BINARY)
#dilated = cv2.dilate(thresh, None, iterations=3)

#cv2.imshow('1',frame1)
#cv2.imshow('2',frame2)

#cv2.imshow('diff',diff)
#cv2.imshow('gray',gray)
#cv2.imshow('blur',blur)
#cv2.imshow('thresh',thresh)
#cv2.imshow('dilated',dilated)


print(frame1.shape)
while cap.isOpened():
    diff = cv2.absdiff(frame1, frame2)
    gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5,5), 0)
    _, thresh = cv2.threshold(blur, 20, 255, cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh, None, iterations=3)
    contours, _ = cv2.findContours(dilated, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        (x, y, w, h) = cv2.boundingRect(contour)

        if cv2.contourArea(contour) <300:
            continue
        cv2.rectangle(frame1, (x, y), (x+w, y+h), (0, 255, 0), 2)
        cv2.putText(frame1, "Status: {}".format('Movement'), (10, 20), cv2.FONT_HERSHEY_SIMPLEX,
                    1, (0, 0, 255), 3)
    #cv2.drawContours(frame1, contours, -1, (0, 255, 0), 2)


    cv2.imshow("feed", frame1)
    frame1 = frame2
    ret, frame2 = cap.read()

    if cv2.waitKey(40) == 27:
        break

cv2.waitKey(0)
cv2.destroyAllWindows()
cap.release()
out.release()
