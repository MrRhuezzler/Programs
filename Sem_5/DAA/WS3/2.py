
rec1Coords = input("(Rec 1) Top Left (x, y): "), input("(Rec 1) Bottom Right (x, y): ")
rec2Coords = input("(Rec 2) Top Left (x, y): "), input("(Rec 2) Bottom Right (x, y): ")

print(rec1Coords, rec2Coords)

def intersect(rec1, rec2):
    if rec1[1][0] < rec2[0][0] or rec2[1][0] > rec1[0][0]:
        return False
    if rec2[1][1] > rec1[0][1] or rec1[1][1] > rec2[0][1]:
        return False
    return True

if intersect(rec1Coords, rec2Coords):
    print("The Rectangles Intersect");
else:
    print("The Rectangles doesn't Intersect");
