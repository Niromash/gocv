package main

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
)

func moveFile(src, destDir string) error {
	// Créer le dossier cible si nécessaire
	if err := os.MkdirAll(destDir, os.ModePerm); err != nil {
		return fmt.Errorf("failed to create directory %s: %v", destDir, err)
	}

	dest := filepath.Join(destDir, filepath.Base(src))

	inputFile, err := os.Open(src)
	if err != nil {
		return fmt.Errorf("failed to open source file %s: %v", src, err)
	}

	outputFile, err := os.Create(dest)
	if err != nil {
		return fmt.Errorf("failed to create destination file %s: %v", dest, err)
	}
	defer outputFile.Close()

	if _, err := io.Copy(outputFile, inputFile); err != nil {
		return fmt.Errorf("failed to copy file from %s to %s: %v", src, dest, err)
	}

	inputFile.Close()
	if err := os.Remove(src); err != nil {
		return fmt.Errorf("failed to remove source file %s: %v", src, err)
	}

	fmt.Printf("Moved file %s to %s\n", src, dest)
	return nil
}

func processDirectory(root string) error {
	return filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		// If the folder is "cvglue", skip it
		if info.IsDir() && info.Name() == "cvglue" {
			return filepath.SkipDir
		}

		// If the folder is "openvino", skip it
		if info.IsDir() && info.Name() == "openvino" {
			return filepath.SkipDir
		}

		// Vérifier si c'est un fichier .cpp
		if !info.IsDir() && filepath.Ext(info.Name()) == ".cpp" {
			var destDir string

			switch {
			case filepath.Base(filepath.Dir(path)) == "cuda":
				destDir = "cvglue/cuda"
			case filepath.Base(filepath.Dir(path)) == "contrib":
				destDir = "cvglue/contrib"
			default:
				destDir = "cvglue/gocv"
			}

			if err := moveFile(path, destDir); err != nil {
				return err
			}
		}

		return nil
	})
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: go run main.go <directory_path>")
		return
	}

	root := os.Args[1]
	if err := processDirectory(root); err != nil {
		fmt.Printf("Error processing directory: %v\n", err)
	} else {
		fmt.Println("Processing completed.")
	}
}
