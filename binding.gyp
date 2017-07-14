{
  "targets": [
    {
      "target_name": "node-helib",
	  "include_dirs" : [
        "<!(node -e \"require('nan')\")",
        "<!(node -e \"require('nnu')\")",
        "dep/HElib/src"
      ],
      "dependencies": [
        "dep/HElib.gyp:helib"
      ],
      "sources": [
        "src/main.cpp",
        "src/CtxtWrap.cpp",
        "src/EncryptedArrayWrap.cpp",
        "src/FHEContextWrap.cpp",
        "src/FHESecKeyWrap.cpp",
        "src/Serializable.cpp"
      ],
      "conditions": [
        [
          "OS != 'win'", {
            "libraries": [
              "-lntl",
              "-lgmp"
            ],
            "cflags_cc": [
              "-frtti",
              "-fexceptions",
              "-Wno-ignored-qualifiers",
              "-Wno-sign-compare"
            ]
          }
        ]
      ]
    }
  ]
}