````markdown name=README.md
# 🎮 Cub3D

Cub3D is a simple 3D game engine inspired by Wolfenstein 3D. This project uses basic raycasting techniques to generate a 3D world from a 2D map. It is developed as part of the 42 School curriculum.

![Wolfenstein 3D]([https://upload.wikimedia.org/wikipedia/en/1/1d/Wolfenstein_3D_Coverart.png](https://media.wired.com/photos/5932a6632a990b06268ac00b/master/w_2240,c_limit/wolfenstein_300px.jpg))

## 📋 Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [What is Raycasting?](#what-is-raycasting)
- [Screenshots](#screenshots)
- [Contributors](#contributors)
- [License](#license)

## ✨ Features
- Generate a 3D world from a 2D map
- Basic raycasting algorithm
- Wall collision detection
- Simple movement and rotation controls
- Texture support
- Sprite support

## 🛠️ Installation

### Requirements
- C compiler (gcc or clang)
- make

### Steps
1. Clone the repository:
    ```sh
    git clone https://github.com/cankarabulut-db/cub3d.git
    cd cub3d
    ```

2. Compile the project:
    ```sh
    make
    ```

3. Run the game:
    ```sh
    ./cub3D map.cub
    ```

## 🚀 Usage

- Use `W`, `A`, `S`, `D` keys to move.
- Use `Left` and `Right` arrow keys to rotate view.

## 🕹️ What is Raycasting?

Raycasting is a technique used to simulate a 3D world by casting rays in a 2D plane. This technique checks if each ray hits a wall and then draws the corresponding vertical slice on the screen based on the hit point. Classic games like Wolfenstein 3D used this technique to create their 3D graphics.

### Raycasting Steps
1. Cast a ray for each vertical line on the screen.
2. Check if the ray hits a wall.
3. Calculate the wall's height based on the hit point.
4. Draw the corresponding vertical slice on the screen.

## 📸 Screenshots

![Screenshot 1](screenshots/screenshot1.png)
![Screenshot 2](screenshots/screenshot2.png)

## 🏷️ Tags
`raycasting`, `3D engine`, `C language`, `game development`, `Wolfenstein 3D`, `42 School`, `graphics programming`

## 🤝 Contributors
- [nkarabul](https://profile.intra.42.fr/users/nkarabul)
- [Other Contributors](https://github.com/username/cub3d/graphs/contributors)

## 📄 License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
````
