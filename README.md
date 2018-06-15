# A wrapper to your default shell

Instead of configuring your alternative zsh/fish/xonfig shell on each terminal emulator (like Konsole), IDE with integrated terminal end etc, you hardcode all them to `/usr/shell` and will get the default shell from `/etc/passwd` and exec to it.

## How to use

* compile:

`gcc -o shell shell.c`

* copy to your wanted bin folder

`sudo ln shell /bin/shell`

then use it (`/bin/shell`) in any place to configure the shell you want to use. So if for instance, you change your shell from bash or csh to zsh, just use the command `chsh -s /bin/zsh` all places that points to `/bin/shell` will open a zsh instead of bash.

