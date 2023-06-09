<!--
Transform images into bizarre absurdity, and experiment with data-image.
-->



![9 1MB](https://user-images.githubusercontent.com/75550631/228114557-75d1867a-eae0-45a6-885d-379e320eac5d.gif)



<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/Overkillographic/main/Other/Frame_1.jpg">
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/Overkillographic/main/Other/Frame_2.jpg">
</p>

These are real-life frames taken from [youtube.com/watch?v=tO01J-M3g0U](https://www.youtube.com/watch?v=tO01J-M3g0U)
GIF is squeezed for render-ability.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/Overkillographic/main/Other/Terminal_8e7e3ab08d8ba018298d10a37d38566f3e9da3b0e0d3fffa648d67646cf0b34a.png">
</p>

[Auditing in the browser?](https://coliru.stacked-crooked.com/a/33c5f88201e0e793)

<br>
<br>

# What else

* Experiment with EXIF stripping.
* Create bar/QR codes through segmented writing.
* Hence a good RICIN system for groupOTP & schemeOTP.
* Mass do things to other files (C++ easily modifiable.)
* Hide information in videos, images, and GIFs.
* Adjust Byte modification for other styles (cpp line 218.)
* Enjoy the crazy acid perspective.

<br>
<br>

# Experiment now

Overkillographic first converts the image to bmp then copies the first 10,000
Bytes from that bmp in order to create a new bmp of the same parameters. Remaining
Bytes can be anything you wish, even terabytes of garbage data; when viewing the
new bmp, n Bytes are read, n being the exact file size of the original bmp.
So, you may write segmented Bytes in repetition and create a bar-code.
Here, after copying the first 10,000 Bytes, remaining Bytes are taken from the
original bmp, modified, and appended to the new bmp until I run out of Bytes
to take, making both bmps equal in size. This new bmp is then converted to jpg. <br>

10,000 is a randomly-chosen quantity, you probably only need 200 Bytes but just to be safe.
Because the first 10,000 Bytes are taken verbatim, you can see a short horizontal segment
of the original image--in the final image (bottoms.)

<br>
<br>

# ML

Because this style of image-building through "bmp header-copying then appending anything"
is certain to give you an image without corruption errors upon viewing, you can convert
training images to bmp and train NNs to predict "next sub-pixel intensities" or whatever
you choose to do to make it happen, then have generated output appended to a bmp
header-copy boilerplate. (You get images generated no matter what.) <br>

For audio on the other hand, there are no complications. See my RICIN cpps.
They essentially write any Bytes to a file without headers or footers.
You then use audio editors to import those files as "Raw Data" and output
as mp3.
