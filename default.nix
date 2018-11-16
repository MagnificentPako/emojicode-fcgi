with import <nixpkgs> {};

stdenv.mkDerivation {
    name = "emojicode-fcgi";
    src  = ./.;
    buildInputs = [ cmake 
                    (import "/etc/nixos/pkgs/emojicode") 
                    gcc
                    ninja
                    fcgi
                  ];
    doCheck = false;
}