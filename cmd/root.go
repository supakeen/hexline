package cmd

import (
	"github.com/spf13/cobra"
)

var (
	// Used for flags.
	devicePath string

	rootCmd = &cobra.Command{
		Use:   "hexline",
		Short: "Show text on the `hexline` PCB.",
	}
)

// Execute executes the root command.
func Execute() error {
	return rootCmd.Execute()
}

func init() {
	rootCmd.PersistentFlags().StringVarP(&devicePath, "device-path", "p", "/dev/ttyACM0", "hexline device path")
}
