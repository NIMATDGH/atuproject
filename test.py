import pygame
import sys

# Initialize Pygame
pygame.init()

# Constants
WINDOW_SIZE = 400
GRID_SIZE = 4
CELL_SIZE = WINDOW_SIZE // GRID_SIZE
CELL_PADDING = 10
BG_COLOR = (187, 173, 160)
CELL_COLOR = (205, 193, 180)
TEXT_COLOR = (119, 110, 101)

# Create the window
screen = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
pygame.display.set_caption('2048')

# Load font
font = pygame.font.Font(None, 36)

def draw_grid(grid):
    for row in range(GRID_SIZE):
        for col in range(GRID_SIZE):
            value = grid[row][col]
            color = CELL_COLOR
            rect = pygame.Rect(col * CELL_SIZE + CELL_PADDING, row * CELL_SIZE + CELL_PADDING, CELL_SIZE - 2 * CELL_PADDING, CELL_SIZE - 2 * CELL_PADDING)
            pygame.draw.rect(screen, color, rect)
            if value != 0:
                text = font.render(str(value), True, TEXT_COLOR)
                text_rect = text.get_rect(center=rect.center)
                screen.blit(text, text_rect)

def main():
    # Sample grid
    grid = [
        [2, 4, 0, 0],
        [0, 2, 4, 0],
        [2, 0, 0, 4],
        [0, 2, 2, 4]
    ]

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        screen.fill(BG_COLOR)
        draw_grid(grid)
        pygame.display.flip()

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
