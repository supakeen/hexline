package cmd

import (
	"github.com/spf13/cobra"
)

var (
	// Used for flags.
	device string

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
	rootCmd.PersistentFlags().StringVarP(&device, "device", "p", "/dev/ttyACM0", "hexline device path")
}
