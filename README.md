<p align="center"><img src="https://github.com/kvpb/randomG7TIDcalculator/blob/master/Screen%20Shot.gif"><br>
<i>What's your number?</i> &#x1F4AF;</p>

<h3 align="center"><b>T.G.'s</b></h3>
<h1 align="center"><b>RCG7TID (Random G7TID Calculator)</b></h1>
<h3 align="center"><b>A random generation I, III & VII secret & trainer ID and trainer shiny & residual value calculator.</b><br>
<b>Un calculateur de numéros d'ID & secret de générations I, III & VII et valeurs chromatique & résiduelle aléatoires.</b></h3>

![version](https://img.shields.io/badge/version-1.00-yellow) ![C++](https://img.shields.io/badge/-C++-649AD2?style=flat&logo=cplusplus&logoColor=004482) ![Makefile](https://img.shields.io/badge/-Makefile-848484?style=flat&logo=cmake&logoColor=D2D2D2) ![macOS](https://img.shields.io/badge/-macOS-FFF?style=flat&logo=apple&logoColor=A7A9AC) ![Linux](https://img.shields.io/badge/-Linux-0094FF?style=flat&logo=linux&logoColor=003778) ![platform](https://gistcdn.githack.com/kvpb/ed57eb3a03f2b5338fbede97e7cf296b/raw/ea6556bb04f592433023533ddbd931cc7d23e92b/apple-F6F6F6D5E1ED1E72F21AD5FD-madeona-1AD5FD1E72F2-mac-F6F6F6D5E1ED.svg)

<pre align="center">
rcg7tid # That's it. C'est tout.
</pre>

---

# &#x1F1FA;&#x1F1F8; US English

This software is an UNIX command-line utility currently programmed in [C++](https://isocpp.org/). It as such requires an [UNIX](http://opengroup.org/unix)-certified or [POSIX](http://get.posixcertified.ieee.org/)-compliant operating system or operating environment such as [macOS](https://www.apple.com/macos) with [Command Line Tools](https://developer.apple.com/library/archive/technotes/tn2339/_index.html), [FreeBSD](https://www.freebsd.org/), [Arch Linux](https://archlinux.org/) or [Fedora Linux](https://fedoraproject.org/), a standard command-line shell like [BASH](https://www.gnu.org/software/bash/), [ZSH](https://www.zsh.org/) or [TCSH](https://www.tcsh.org/) and the [GNU Compiler Collection](https://gcc.gnu.org/) or [CLANG](https://clang.llvm.org/) standard C++ optimizing compilers and the [Make](https://www.gnu.org/software/make/) build automation tool. The user may set it up and use it from a command-line interface in a graphical user interface via a terminal emulator, e.g. [iTerm2](https://iterm2.com), [Terminator](https://gnome-terminator.org) or [the integrated terminal of Visual Studio Code](https://code.visualstudio.com/docs/editor/integrated-terminal). These instructions assume the user knows how to use an UNIX shell in a POSIX-compliant development and runtime environment.<br>
&nbsp;&nbsp;&nbsp;&nbsp;The user shall note 'generation N ID number' in this manual refers to all types of numbers from generation I to generation N, e.g. a generation I trainer ID number, a generation III secret ID number, a generation IV trainer shiny value, a generation IV trainer residual value, a generation VII trainer ID number and a generation VII secret ID number by 'generation VII ID number'. The user also may have noticed 'IDNo' originally meant the generation VII trainer ID number in the Japanese versions of the games but means in this source code the full generation VII ID number not split into a generation VII trainer ID number and a generation VII secret ID number.

## Set up

Let us now declare a few functions and variables for the sake of brevity. The user of course can forgo this and do it all by themselves manually, **but if you do so, please do not ask to be helped with this software.**

```sh
pathname()
{
	printf "$(cd "$(dirname "${1}")" && pwd -P)/$(basename "${1}")"'\n'
}

URL="https://github.com/kvpb/randomG7TIDcalculator"
dir="${URL%/*}" && dir="${dir##*/}"
repo="${URL##*/}"
progname="rcg7tid"
bin="$(pathname ${repo})/bin/${progname}"
```

**The user should avoid setting this software up from a critical location in the file system such as `/` or the parent directory of other software.** I advise doing so from a dedicated, throwaway directory. The user therefore should do thus:

```sh
mkdir ${dir} # preferably from ${HOME}.
cd ${dir}
```

Once the user has obtained the sources of this software, they may proceed to compile them. They should do thus:

```sh
git clone ${URL}
cd ${repo}
# preferably from ${dir}/.
make # from ${repo}/.
```

The executable file at this point should be in `${repo}/bin/`. The user should be able to execute it.

## Use

The user at this point may use the software. They just have to enter the pathname of the executable file. They can do thus:

```sh
cd bin # from ${repo}/.
```

If the user wants to randomly generate a generation VII ID number, they have to do it like this:

```tcsh
${bin} # from any directory in the file system.
```

# &#x1F1EB;&#x1F1F7; Français FR

Ce logiciel est un utilitaire en ligne de commande pour le moment programmé en [C++](https://isocpp.org/). Il requiert un système d'exploitation ou environnement d'exploitation certifié [UNIX](http://opengroup.org/unix) ou conforme à [POSIX](http://get.posixcertified.ieee.org/) tel que [macOS](https://www.apple.com/macos) avec [Command Line Tools](https://developer.apple.com/library/archive/technotes/tn2339/_index.html), [FreeBSD](https://www.freebsd.org/), [Arch Linux](https://archlinux.org/) ou [Fedora Linux](https://fedoraproject.org/), un interpréteur de commandes standard comme [BASH](https://www.gnu.org/software/bash/), [ZSH](https://www.zsh.org/) ou [TCSH](https://www.tcsh.org/), un compilateur d'optimisation standard du C++ [GNU Compiler Collection](https://gcc.gnu.org/) ou [CLANG](https://clang.llvm.org/) et le moteur de production [Make](https://www.gnu.org/software/make/). L'utilisateur peut l'installer et utiliser depuis une interface en ligne de commande dans une interface graphique via un terminal virtuel, e.g. [iTerm2](https://iterm2.com), [Terminator](https://gnome-terminator.org) ou [le terminal intégré de Visual Studio Code](https://code.visualstudio.com/docs/editor/integrated-terminal). Ces instructions supposent l'utilisateur savoir se servir d'un interpréteur de commandes pour UNIX dans un environnement de développement et d'exécution conforme à POSIX.
<br>&nbsp;&nbsp;&nbsp;&nbsp;L'utilisateur doit comprendre 'numéro d'ID de génération N' dans ce manuel sous-entendre tous les types de numéros de la génération I à la génération N, e.g. un numéro d'ID de génération I, un numéro secret de génération III, une valeur de chromatique de génération IV, une valeur résiduelle de chromatique de génération IV, un numéro d'ID de génération VII et un numéro secret de génération VII par 'numéro de génération VII'. L'utilisateur aussi a pu remarquer 'IDNo' initialement signifier dans les versions japonaises le numéro d'ID de génération VII mais vouloir dire dans le source code de ce logiciel le numéro de génération VII entier pas encore scindé en un numéro d'ID de génération VII et un numéro secret de génération VII.

## Installer

Déclarons à présent quelques fonctions et variables par souci de brièveté. L'utilisateur peut bien sûr passer outre et faire tout ceci par lui-même, **mais si vous le faites, veuillez en cas de problème ne pas demander à être aidé avec ce logiciel.**

```sh
pathname()
{
	printf "$(cd "$(dirname "${1}")" && pwd -P)/$(basename "${1}")"'\n'
}

URL="https://github.com/kvpb/randomG7TIDcalculator"
dir="${URL%/*}" && dir="${dir##*/}"
repo="${URL##*/}"
progname="rcg7tid"
bin="$(pathname ${repo})/bin/${progname}"
```

**L'utilisateur devrait éviter d'installer ce logiciel depuis un point critique du système de fichiers tel que `/` ou le répertoire parent d'un autre logiciel.** Je conseille de le faire depuis un répertoire temporaire dédié. L'utilisateur peut alors procéder ainsi :

```sh
mkdir ${dir} # de preference depuis ${HOME}.
cd ${dir}
```

Lorsque l'utilisateur a obtenu les sources de ce logiciel, il peut en venir à les compiler. Il devrait procéder ainsi :

```sh
git clone ${URL}
cd ${repo}
# de preference depuis ${dir}/.
make # depuis ${repo}/.
```

Le fichier exécutable est censé à ce stade se trouver dans `${repo}/bin/`. L'utilisateur devrait pouvoir le faire s'exécuter.

## Utiliser

L'utilisateur peut désormais utiliser le logiciel. Il suffit d'entrer le chemin d'accès du fichier exécutable. Il peut procéder ainsi :

```sh
cd bin # depuis ${repo}/.
```

Si l'utilisateur veut générer au hasard un numéro de génération VII, il a à y procéder ainsi:

```tcsh
${bin} # depuis tout repertoire dans le systeme de fichiers.
```

---

<p align="center"><br>
<a href="http://kvpb.fr"><img src="https://gistcdn.githack.com/kvpb/c80594e9079e857c55c36dec49a1a2d7/raw/eec54d5821dc092ad910635141c4e4feebf07565/kvpbssymbol.svg"></a><br>
<b>Karl V. P. B. `<code>kvpb</code>`<br>
カール・ビンセント・ピエール・ベルティン</b><br>
<b>AKA&nbsp;&nbsp;Karl Thomas George West `<code>ktgw</code>`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;カール・トーマス・ジョージ・ウェスト</b><br>
medical student<br>
<br>
<span style="display:block;text-align:center"><a href="https://twitter.com/ktgwkvpb"><img src="https://gistcdn.githack.com/kvpb/20db04ea32721c7a968f198dbbdf688d/raw/1b2126ef7f572709f8cca49216e0021f324a2639/twitter.svg" alt="Twitter"></a></span><br>
<img src="https://gistcdn.githack.com/kvpb/f5f75716dd024cc48f8dc28176c0b642/raw/e5344bebf926b378faeb208724ae97f4e06639ca/kvpbsesrbrating.svg"></p>
