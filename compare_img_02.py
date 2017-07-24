h1 = Image.open("image1").histogram()
h2 = Image.open("image2").histogram()

rms = math.sqrt(reduce(operator.add,
    map(lambda a,b: (a-b)**2, h1, h2))/len(h1))
