
![GitHub](https://img.shields.io/github/license/mikeanth-dev/pifetch?style=for-the-badge)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/mikeanth-dev/pifetch?style=for-the-badge)
![GitHub top language](https://img.shields.io/github/languages/top/mikeanth-dev/pifetch?style=for-the-badge)

# Pifetch

A custom fetch script to dsiplay some Raspberry related information and Docker stats

Example:

![Awesome Example Image](https://github.com/mikeanth-dvlp/pifetch/blob/master/assets/example.png)

## Prerequisites

For this piece of code to work, you need to have `docker`, `lshw` and `vcgencmd` available on your Raspberry Pi.

For `docker`, you can follow [this guide](https://phoenixnap.com/kb/docker-on-raspberry-pi).
However, with the volatility of the interwebs, I'll provide a short summary here.

``` bash
curl -fsSL https://get.docker.com -o get-docker.sh  # download the official install script
sudo sh get-docker.sh                               # run it
sudo usermod -aG docker $(whoami)                   # add the current user to the docker group
exit                                                # you need to log out and log back in for the change to take effect

# log back in

docker version                                      # to test the installation
```

For `lshw`, a basic `apt-get install` is sufficient: `sudo apt-get install lshw`

As for `vcgencmd`, it comes preinstalled in Raspbian, so I suggest you use that. For other distros, you have to look it up yourself.

## How to install

### Download the precompiled binaries

Make sure to download the right binary for your architecture. On the releases page, there are precompiled binaries for either `x86_64`, which would be your typical 64bit desktop, `aarch64`, which would be a 64bit OS running on an ARM architecture, such as the Pi4 running Ubuntu Server 64bit, and `armv6l` which would be a 32bit OS running on an ARM architecture, such as the Pi0 running Raspbian.

``` bash
wget https://github.com/mikeanth-dev/pifetch/releases/download/v1.0.0/pifetch-aarch64
chmod +x ./pifetch-aarch64;                 # make the file executable
sudo mv ./pifetch-aarch64 /bin/pifetch;     # add it to path
```

### Automated install via Ansible

You can use an automation tool, like Ansible to script out this installation.   
In your playbook/role, you can simply add the following task, and Ansible will take care of it for you!

``` yaml
...
- name: Download pifetch v1.0.0
  become: true
  get_url:
    url: 'https://github.com/mikeanth-dev/pifetch/releases/download/v1.0.0/pifetch-{{ ansible_architecture }}'
    dest: '/bin/pifetch'
    mode: '0755'
    owner: root
    group: root
...
```

> Note: The arch in the release name matches the ansible {{ ansible_architecture }} for all supported architectures.

### Build from source

Prerequisites: `g++` & `make`

Clone this repository and compile the project via the makefile:

``` bash
git clone https://github.com/mikeanth-dev/pifetch.git;
cd pifetch;
make;
```

You should now have a new file called `pifetch` in that directory. You can execute it by running `./pifetch`. However, it would be more convenient to have it readily available at all times, so i recommend copying it to `/bin/` via : `sudo mv ./pifetch /bin/pifetch`.

## How to uninstall

Assuming you follwed the steps mentioned above, simply remove the binary you copied to `/bin` by `sudo rm /bin/pifetch`.

## Feedback, suggestions and help

For feedback, suggestions, bug reports etc., feel free to e-mail me at 'mike.anth99@gmail.com'.

---

_a project by Mircea-Pavel Anton (Mike Anthony)_
