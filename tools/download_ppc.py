import urllib.request
import sys
import os
import stat
import platform
import tempfile
import zipfile

if sys.platform == "cygwin":
	sys.exit(
		f"Cygwin/MSYS2 is not supported."
		f"\nPlease use native Windows Python instead."
		f"\nPlease run pacman -R python in msys2."
		f"\n(Current path: {sys.executable})"
	)

REPO = "https://github.com/encounter/gc-wii-binutils"


def main() -> None:
	output = f"{os.path.dirname(__file__)}/powerpc"

	uname = platform.uname()
	system = uname.system.lower()
	arch = uname.machine.lower()
	if system == "darwin":
		system = "macos"
		arch = "universal"
	if arch == "amd64":
		arch = "x86_64"
	if arch == "x86_32":
		arch = "i686"

	with tempfile.TemporaryDirectory() as tmp_dir:
		tmp_zip = f"{tmp_dir}/powerpc.zip"
		url = f"{REPO}/releases/latest/download/{system}-{arch}.zip"

		urllib.request.urlretrieve(url, tmp_zip)
		with zipfile.ZipFile(tmp_zip) as zip_file:
			zip_file.extractall(output)

	#st = os.stat(output)
	#os.chmod(output, st.st_mode | stat.S_IEXEC)
	#FIXME: the above doesn't work for whatever reason
	for filename in os.listdir(output):
		f = os.path.join(output, filename)
		#The Linux versions of encounter's dkp binutils are missing the prefix,
		#so this is needed until the issue is fixed
		if not filename.startswith("powerpc-eabi-"):
			new_filename = "powerpc-eabi-" + filename
			new_file = os.path.join(output, new_filename)
			os.rename(f, new_file)
			f = new_file

		st = os.stat(f)
		os.chmod(f, st.st_mode | stat.S_IEXEC)


if __name__ == "__main__":
	main()
