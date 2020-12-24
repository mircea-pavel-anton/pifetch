# Pifetch
A custom fetch script to dsiplay some Raspberry related information and Docker stats

Example:
![Awesome Example Image](https://github.com/mikeanth-dvlp/pifetch/blob/master/assets/example.png)

## Prerequisites
For this piece of code to work, you need to have `docker`, `lshw` and `vcgencmd` available on your Raspberry Pi.

For `docker`, you can follow [this guide](https://phoenixnap.com/kb/docker-on-raspberry-pi).
However, with the volatility of the interwebs, I'll provide a short summary here.
```
curl -fsSL https://get.docker.com -o get-docker.sh # download the official install script
sudo sh get-docker.sh # run it
sudo usermod -aG docker $(whoami) # add the current user to the docker group
exit # you need to log out and log back in for the change to take effect

docker version # to test the installation
```
For `lshw`, a basic `apt-get install` is sufficient: `sudo apt-get install lshw`

As for `vcgencmd`, it comes preinstalled in Raspbian, so I suggest you use that. For other distros, you have to look it up yourself.

## How to install
1. Clone this repo into a dedicated directory, such as `/usr/local/src/pifetch`
```
sudo git clone https://github.com/mikeanth-dvlp/pifetch.git /usr/local/src/pifetch
# sudo is needed to create that directory. If you want to install it somewhere else, feel free to ignore it
```
2. Navigate into the downloaded directory: `cd /usr/local/src/pifetch`
3. Run `sudo make`
4. Make the following addition to your `~/.bash_aliases` file:
```
alias pifetch='/usr/local/src/pifetch/pifetch'
```
5. Load the new `.bash_aliases` file via `source ~/.bashrc`
6. You're done. There's nothing more to do.

<br>

## Feedback, suggestions and help

For feedback, suggestions, bug reports etc., feel free to e-mail me at 'mike.anth99@gmail.com'.

---

_a project by Mircea-Pavel Anton (Mike Anthony)_
