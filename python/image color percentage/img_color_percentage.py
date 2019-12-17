from PIL import Image

img = Image.open('kamienica2.png').convert('RGB')
colors = img.getcolors(maxcolors=10000)
size = img.size
img_surface = size[0] * size[1]

w_count = 0
b_count = 0
r_count = 0
p_left = 0
colors_left = []

for color in colors:
    count = color[0]
    r, g, b = color[1]

    if r > 200 and g > 200 and b > 200:
        w_count += count
        continue

    if r < 60 and g < 60 and b < 60:
        b_count += count
        continue

    if r > 200 and g < 40 and b < 40:
        r_count += count
        continue

    p_left += count
    colors_left.append(color)

brw = w_count + r_count + b_count
bw = brw - r_count
b_perc = b_count / bw * 100
w_perc = w_count / bw * 100

print(f"Red: {r_count} px | Black: {b_count} px | White {w_count} px | Left: {p_left} px")
print(f"Black: {b_perc} % | White: {w_perc} %")

# for color in colors_left:
#     if color[0] > 1000:
#         print(color)
# print(p_left)
# print(p_left + w_count + b_count + r_count == img_surface)

