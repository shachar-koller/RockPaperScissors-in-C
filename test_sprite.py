
import pygame

pygame.init()
screen = pygame.display.set_mode((600, 400))
clock = pygame.time.Clock()
dt = 0


# Load and scale sprites
sprite = pygame.image.load("rock.png").convert_alpha()
sprite = pygame.transform.scale(sprite, (50, 50))
sprite_rect = sprite.get_rect(center=(150, 200))

sprite1 = pygame.image.load("paper.png").convert_alpha()
sprite1 = pygame.transform.scale(sprite1, (50, 50))
sprite_rect1 = sprite1.get_rect(center=(300, 200))

sprite2 = pygame.image.load("scissors.png").convert_alpha()
sprite2 = pygame.transform.scale(sprite2, (50, 50))
sprite_rect2 = sprite2.get_rect(center=(450, 200))


# Load and scale user and cpu icons
user_icon = pygame.image.load("user.png").convert_alpha()
user_icon = pygame.transform.scale(user_icon, (100, 100))
user_icon_rect = user_icon.get_rect()
user_icon_rect.bottomleft = (10, 390)  # 10px from left, 10px from bottom

vs_icon = pygame.image.load("vs.png").convert_alpha()
vs_icon = pygame.transform.scale(vs_icon, (50, 50))
vs_icon_rect = vs_icon.get_rect()
vs_icon_rect.bottomleft = (280, 390)

cpu_icon = pygame.image.load("cpu.png").convert_alpha()
cpu_icon = pygame.transform.scale(cpu_icon, (100, 100))
cpu_icon_rect = cpu_icon.get_rect()
cpu_icon_rect.bottomright = (590, 390)  # 10px from right, 10px from bottom

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Detect clicks
        if event.type == pygame.MOUSEBUTTONDOWN:
            if sprite_rect.collidepoint(event.pos):
                print("Rock clicked!")
            if sprite_rect1.collidepoint(event.pos):
                print("Paper clicked!")
            if sprite_rect2.collidepoint(event.pos):
                print("Scissors clicked!")

    screen.fill(("white"))
    screen.blit(sprite, sprite_rect)
    screen.blit(sprite1, sprite_rect1)
    screen.blit(sprite2, sprite_rect2)
    screen.blit(user_icon, user_icon_rect)
    screen.blit(cpu_icon, cpu_icon_rect)
    screen.blit(vs_icon, vs_icon_rect)
    pygame.display.flip()
