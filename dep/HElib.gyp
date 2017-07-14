{
  "targets": [
    {
      "target_name": "helib",
      "type": "static_library",
      "sources": [
        "HElib/src/KeySwitching.cpp",
        "HElib/src/EncryptedArray.cpp",
        "HElib/src/FHE.cpp",
        "HElib/src/Ctxt.cpp",
        "HElib/src/CModulus.cpp",
        "HElib/src/FHEContext.cpp",
        "HElib/src/PAlgebra.cpp",
        "HElib/src/DoubleCRT.cpp",
        "HElib/src/NumbTh.cpp",
        "HElib/src/bluestein.cpp",
        "HElib/src/IndexSet.cpp",
        "HElib/src/timing.cpp",
        "HElib/src/replicate.cpp",
        "HElib/src/hypercube.cpp",
        "HElib/src/matching.cpp",
        "HElib/src/powerful.cpp",
        "HElib/src/BenesNetwork.cpp",
        "HElib/src/permutations.cpp",
        "HElib/src/PermNetwork.cpp",
        "HElib/src/OptimizePermutations.cpp",
        "HElib/src/eqtesting.cpp",
        "HElib/src/polyEval.cpp",
        "HElib/src/extractDigits.cpp",
        "HElib/src/EvalMap.cpp",
        "HElib/src/recryption.cpp",
        "HElib/src/debugging.cpp",
        "HElib/src/matmul.cpp",
        "HElib/src/matmul1D.cpp",
        "HElib/src/blockMatmul.cpp",
        "HElib/src/blockMatmul1D.cpp"
      ],
      "conditions": [
        [
          "OS != 'win'", {
            "cflags_cc": [
              "-frtti",
              "-fexceptions",
              "-Wno-maybe-uninitialized",
              "-Wno-ignored-qualifiers",
              "-Wno-unused-variable",
              "-Wno-sign-compare",
              "-Wno-return-type"
            ]
          }
        ]
      ]
    }
  ]
}