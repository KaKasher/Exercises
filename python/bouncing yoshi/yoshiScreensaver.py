import pygame, sys
pygame.init()

speed = [2, 2]
black = 0, 0, 0

screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
width, height = screen.get_size()

yoshi = pygame.image.load("bigYoshi.png")
yoshirect = yoshi.get_rect()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN: sys.exit()

    yoshirect = yoshirect.move(speed)
    if yoshirect.left < 0 or yoshirect.right > width:
        speed[0] = -speed[0]
    if yoshirect.top < 0 or yoshirect.bottom > height:
        speed[1] = -speed[1]

    screen.fill(black)
    screen.blit(yoshi, yoshirect)
    pygame.display.flip()
