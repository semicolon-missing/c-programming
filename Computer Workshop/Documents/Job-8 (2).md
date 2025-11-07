
# Computer Workshop

## Job - 8

Practical 8: Dual-Booting Windows and Pop!_OS

Aim: To document the process of installing Pop!_OS alongside an existing Windows installation, allowing the user to choose which operating system to boot into.

Software Required:
    A computer with Windows already installed.
    A USB drive with at least 8GB of storage.
    BalanEtcher or Rufus for creating a bootable USB drive.
    Pop!_OS ISO file (Nvidia version if applicable).

Procedure:

### Part 1: Preparing Windows

1.  Back up your data: Before making any changes, back up all important files from your Windows installation.
2.  Create free space for Pop!_OS:
        Open "Disk Management" in Windows.
        Right-click on your main Windows partition (usually C:) and select "Shrink Volume".
        Enter the amount of space you want for Pop!_OS (at least 20GB, 100GB or more is recommended).
        Click "Shrink". This will create "Unallocated" space.
3.  Disable Fast Startup:
        Go to Control Panel > Hardware and Sound > Power Options > Choose what the power buttons do.
        Click "Change settings that are currently unavailable".
        Uncheck "Turn on fast startup".
        Save changes.

### Part 2: Creating a Bootable USB

1.  Download Pop!_OS: Get the appropriate ISO from [https://pop.system76.com](https://pop.system76.com).
2.  Create bootable USB: Use BalenaEtcher or Rufus to flash the ISO to your USB drive.

### Part 3: Installing Pop!_OS

1.  Boot from USB:
        Restart your computer and enter the BIOS/UEFI settings.
        Disable "Secure Boot".
        Set the USB drive as the primary boot device.
        Save changes and exit.
2.  Start Installation:
        Boot from the USB drive and select "Try or Install Pop!_OS".
        Choose your language and keyboard layout.
        Select "Custom (Advanced)" when asked for the installation type.
3.  Partitioning:
        You will see the "Unallocated" space you created. You need to create a few partitions in this space.
        EFI System Partition:
            Size: 512 MB
            File System: FAT32
            Mount Point: `/boot/efi`
        Root Partition:
            Size: At least 20GB (100GB+ recommended)
            File System: ext4
            Mount Point: `/`
        (Optional) Swap Partition:
            Size: Equal to your RAM
            File System: linux-swap
        (Optional) Home Partition:++
            Size: Remaining space
            File System: ext4
            Mount Point: `/home`
4.  Complete Installation:
        Apply the changes and continue with the installation.
        Create your user account.
        Restart when prompted and remove the USB drive.

### Part 4: Configuring the Bootloader

Pop!_OS uses `systemd-boot`, which needs to be configured to show Windows.

1.  Boot into Pop!_OS.
2.  Open a terminal.
3.  Run the following commands:
    ```bash
    sudo apt update
    sudo apt install os-prober
    sudo os-prober
    ```
4.  Copy Windows boot files:
        Find the Windows EFI partition (it's a small FAT32 partition). Let's say it's `/dev/sda1`.
        Run these commands, replacing `/dev/sda1` with your Windows EFI partition:
    ```bash
    sudo mkdir /mnt/windows
    sudo mount /dev/sda1 /mnt/windows
    sudo cp -r /mnt/windows/EFI/Microsoft /boot/efi/EFI/
    sudo umount /mnt/windows
    ```
5.  Set a boot menu timeout:
        Edit the file `/boot/efi/loader/loader.conf`:
    ```bash
    sudo nano /boot/efi/loader/loader.conf
    ```
        Add the line `timeout 10` to the file.
        Save the file (Ctrl+O, Enter) and exit (Ctrl+X).
6.  Reboot. You should now see a menu to choose between Pop!_OS and Windows.

Output:
A computer that can boot into either Windows or Pop!_OS.
