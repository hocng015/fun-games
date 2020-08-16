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
bulletY_Vel = 10
bullet_state = "ready"
bullet2X = 0
bullet2Y = 480
bullet2X_Vel = 0
bullet2Y_Vel = 5
bullet2_state = "ready"
playerX = 370
playerY = 480
playerX_Vel = 3
playerY_Vel = 5
enemyImg = pygame.image.load('evil.png')
enemyX = random.randint(0, 736)
enemyY = random.randint(0, 100)
enemyX_Vel = 4
enemyY_Vel = 40
score_value = 0
font = pygame.font.SysFont('freesansbold.tff', 32)
textX = 10
textY = 10
a = 0
b = 0
direction = ""


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


def fire2(x, y):
    global bullet2_state
    bullet2_state = "fire"
    screen.blit(bullet2, (x + 16, y + 10))


def mov_background(x, y):
    screen.blit(background, (x, y))


def reverse(x):
    if x == -1100:
        direction = "negative"
    if x == 0:
        direction = "positive"


while running:
    isCollision = collision(enemyY, enemyX, bulletX, bulletY)
    screen.fill((75, 0, 130))
    if (enemyY > 600) or collide_player(enemyY, enemyX, playerX, playerY):
        screen.blit(gameover, (-300, -300))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
    else:
        mov_background(a, b)
        reverse(a)
        if direction == "negative":
            a += 0.5
            b += 0.5
        if direction == "positive":
            a -= 0.5
            b -= 0.5
        # EVENT
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                playerX -= playerX_Vel
            elif event.key == pygame.K_RIGHT:
                playerX += playerX_Vel
            elif event.key == pygame.K_SPACE:
                if bullet_state is "ready":
                    bulletX = playerX
                    fire(bulletX, bulletY)
        #            if bullet_state is "fire":
        #               if event.key == pygame.K_SPACE:
        #                   if bullet2_state is "ready":
        #                      bullet2X = playerX
        #                       fire2(bullet2X, bullet2Y)
        # GAME LOGIC
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
        if bullet_state is "fire":
            fire(bulletX, bulletY)
            bulletY -= bulletY_Vel
        if bulletY <= 0:
            bulletY = 480
            bullet_state = "ready"
        if isCollision:
            bulletY = 480
            bullet_state = "ready"
            score_value += 1
            enemyX = random.randint(0, 736)
            enemyY = random.randint(0, 100)
        if bullet2_state is "fire":
            fire(bullet2X, bullet2Y)
            bullet2Y -= bullet2Y_Vel
        if bullet2Y <= 0:
            bullet2Y = 480
            bullet2_state = "ready"
        enemyX += enemyX_Vel
        enemy(enemyX, enemyY)
        showscore()
    pygame.display.update()
