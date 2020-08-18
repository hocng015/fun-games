import pygame
import random
import math

pygame.init()
screen = pygame.display.set_mode((800, 600))
running = True
pygame.display.set_caption("Space Invaders")
icon = pygame.image.load('planet.png')
pygame.display.set_icon(icon)
background = pygame.image.load('background.jpg')
gameover = pygame.image.load('gameover.jpg')
bullet = pygame.image.load('bullet.png')
bullet2 = pygame.image.load('bullet.png')
playerImg = pygame.image.load('space-invaders.png')
deadImg = pygame.image.load('skull.png')
deadX = 0
deadY = 0
bulletX = 0
bulletY = 480
bulletX_Vel = 0
bulletY_Vel = 6
bullet_state = "ready"
playerX = 370
playerY = 480
playerX_Vel = 3
playerY_Vel = 5
enemyImg = pygame.image.load('evil.png')
enemyX = random.randint(0, 736)
enemyY = random.randint(0, 100)
bullet2X = 0
bullet2Y = enemyY
bullet2X_Vel = 0
bullet2Y_Vel = 1
bullet2_state = "ready"
enemyX_Vel = 4
enemyY_Vel = 40
score_value = 0
font = pygame.font.SysFont('freesansbold.tff', 32)
textX = 10
textY = 10
a = 0
b = 0
direction = "negative"
last_tick = pygame.time.get_ticks()


def showscore():
    score = font.render("SCORE:" + str(score_value), True, (255, 255, 255))
    screen.blit(score, (10, 10))


def player(x, y):
    screen.blit(playerImg, (x, y))


def enemy(x, y):
    screen.blit(enemyImg, (x, y))


def fire(x, y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bullet, (x + 16, y + 10))


def dead(x, y):
    screen.blit('skull.png', (x, y))


def collision(enemyY, enemyX, bulletX, bulletY):
    distance = math.sqrt((math.pow(enemyX - bulletX, 2)) + (math.pow(enemyY - bulletY, 2)))
    if distance <= 27:
        return True
    else:
        return False


def collide_player(enemyY, enemyX, playerX, playerY):
    distance = math.sqrt((math.pow(enemyX - playerX, 2)) + (math.pow(enemyY - playerY, 2)))
    if distance <= 27:
        return True
    else:
        return False


def attacked(bullet2X, bullet2Y, playerX, playerY):
    distance = math.sqrt((math.pow(bullet2X - playerX, 2)) + (math.pow(bullet2Y - playerY, 2)))
    if distance <= 27:
        return True
    else:
        return False


def enemyfire(x, y):
    global bullet2_state
    bullet2_state = "fire"
    screen.blit(bullet2, (x + 16, y + 10))


def mov_background(x, y):
    screen.blit(background, (x, y))


while running:
    isCollision = collision(enemyY, enemyX, bulletX, bulletY)
    screen.fill((75, 0, 130))
    if (enemyY > 600) or collide_player(enemyY, enemyX, playerX, playerY):
        screen.blit(gameover, (a, b))
        if a == -1200:
            direction = "positive"
        if a == 0:
            direction = "negative"
        if direction == "negative":
            a -= 0.5
            b -= 0.5
        if direction == "positive":
            a += 0.5
            b += 0.5
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
    else:

        # BACKGROUND MOTION
        mov_background(a, b)
        if a == -1200:
            direction = "positive"
        if a == 0:
            direction = "negative"
        if direction == "negative":
            a -= 0.5
            b -= 0.5
        if direction == "positive":
            a += 0.5
            b += 0.5

        # EVENT
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            playerX -= playerX_Vel
        if keys[pygame.K_RIGHT]:
            playerX += playerX_Vel
        if keys[pygame.K_UP]:
            playerY -= playerY_Vel
        if keys[pygame.K_DOWN]:
            playerY += playerY_Vel
        if keys[pygame.K_SPACE]:
            if bullet_state == "ready":
                bulletX = playerX
                fire(bulletX, bulletY)

        # GAME LOGIC

        # BOUNDS
        if playerX >= 736:
            playerX = 736
        elif playerX <= 0:
            playerX = 0
        player(playerX, playerY)
        if enemyX <= 0:
            enemyX_Vel = 1
            enemyY += enemyY_Vel
        elif enemyX >= 736:
            enemyX_Vel = -1
            enemyY += enemyY_Vel
        enemyX += enemyX_Vel
        enemy(enemyX, enemyY)

        # BULLETS
        #        if bullet2_state == "ready":
        #            bullet2X = enemyX
        #            enemyfire(bullet2X, bullet2Y)
        #            bullet2Y += bullet2Y_Vel
        #        if bullet2Y >= 600:
        #            bullet2Y = enemyY

        if bullet_state == "fire":
            fire(bulletX, bulletY)
            bulletY -= bulletY_Vel
        if bulletY <= 0:
            bulletY = playerY
            bullet_state = "ready"
        if isCollision:
            bulletY = playerY
            bullet_state = "ready"
            score_value += 1
            enemyX = random.randint(0, 736)
            enemyY = random.randint(0, 100)
        if bullet2_state == "fire":
            fire(bullet2X, bullet2Y)
            bullet2Y -= bullet2Y_Vel
        if bullet2Y <= 0:
            bullet2Y = 480
            bullet2_state = "ready"
        showscore()
    pygame.display.update()
